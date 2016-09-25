/*
Miscellaneous:
    01 asm declaration
    02 extending the namespace std
    03 undefined behavior

    04 RAII ( Resource Acquisition Is Initialization )

    05 The rule of three / five / zero
    06 The as-if rule
    07 copy elision
    08 Empty base optimization
*/
//
//
/// 04 RAII ( Resource Acquisition Is Initialization )
// "Resource Acquisition Is Initialization" or RAII, is a C++ programming technique
// which binds the life cycle of a resource ( allocated memory, open socket. open file,
// mutex, database connection - anything that exist in limited supply ) to the lifetime
// of an object with automatic storage duration.
//
// for more detail read the main site
std::mutex m;
void bad (){
    m.look();       // acquire the mutex
    f();            // if f() throws an exception, the mutex in never released
    if (!everything_ok());  return;     // early return, the mutex is never released
    m.unlock();     // only if execution reaches this statement, the mutex is released
}

void good(){
    std::lock_qurad<std::mutex> lk(m);  // RAII class: mutux acquisition is initialization
    f();            // if f() throws an exception, the muxex is released
    if (!everything_ok()) return;       // early return, the mutex is released
}   // if the function returns normally, the mutex is released
//
//
//
// The standard library
// The C++ library classes that manage their own resources follow RAII: std::string
// std::vector, std::thread, and many others allocated their resources in constructor
// ( which throw exception on error) , release them in their destructors
// ( which never throw ) and do not require explicit cleanup.
//
// In addition, the standard library offers several RAII wrappers to manage
// user-provided resource:
// > std::unique_ptr and std::shared_ptr to manage dynamically-allocated memory or with
//   a user provided deleter, any resource represented by a plain pinter
// > std::lock_gurad, std::unique_lock, std::shared_lock to manage mutexes
