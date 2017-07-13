/*
        std::hash
        *********

defined in header <functional>

The hash template defines a function object that implements a hash
function, Instances of this function object satisfy Hash.
(for more detail see the main website)

    Member Type:
        argument_type       key
        result_type         std::size_t

    Member Function:
        constructor
        operator


    Standard Specialization for Basic Type:
        template<> struct hash<bool>;
        template<> struct hash<char>;
        template<> struct hash<signed char>;
        template<> struct hash<unsigned char>;
        template<> struct hash<char16_t>;
        template<> struct hash<char32_t>;
        template<> struct hash<wchar_t>;
        template<> struct hash<short>;
        template<> struct hash<unsigned short>;
        template<> struct hash<int>;
        template<> struct hash<unsigned int>;
        template<> struct hash<long>;
        template<> struct hash<long long>;
        template<> struct hash<unsigned long>;
        template<> struct hash<unsigned long long>;
        template<> struct hash<float>;
        template<> struct hash<double>;
        template<> struct hash<long double>;
        template< class T > struct hash<T*>;

    In addition to the above, standard library provides specializations for
    all (scoped and unscoped) enumeration types (which are not required,
    but usually are implemented as std::hash<std::underlying_type<Enum>::type>)

    Standard Specialization for Library Type:
        std::hash<std::string>
        std::hash<std::u16string>
        std::hash<std::u32string>
        std::hash<std::wstring>

        std::hash<std::error_code>
        std::hash<std::bitset>
        std::hash<std::unique_ptr>
        std::hash<std::shared_ptr>
        std::hash<std::type_index>
        std::hash<std::vector<bool>>    hash support for std::vector<bool>
        std::hash<std::thread::id>

*/
