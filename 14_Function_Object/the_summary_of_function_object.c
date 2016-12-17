/*

        Function Object
        ***************

A function object is any object for which the function call operator is defined.
C++ provides many build-in function object as well as support for certain and
manipulation of new function object.

1. Polymorphic Function Wrapper
    1.1 function:
        Class template std::function is a general-purpose polymorphic function wrapper.
        Instances of std::function can store, copy, and invoke any Callable target - function,
        lambda expression, bind expression, or other function objects, as well as pointer
        to member function and pointer to member data.
        The stored callable object is called the target of std::function. If a std::function
        contains no target, it is called empty invoking the target of an empty std::function
        result in std::bad_function_call exception begin thrown.
        std::function satisfies the requirement of CopyConstructible and CopyAssignable.

        member type:
            result_type
            argument_type
            first_argument_type
            second_argument_type

        member function:
            constructor
            destructor
            operator =
            swap
            assign
            operator bool
            operator () parenthesis

        target access:
            target_type
            target

        non-member function
            std::swap ( std::function )
            operator == , !=

        helper class
            std::uses_allocator< std::function >

    --------------------------------------------
    1.2 mem_fncreates:
        Function template std::mem_fn generates wrapper objects for pointers to members,
        which can store, copy, and invoke a pointer to member. Both reference and pointer
        (including smart pointers) to an object cab be used when invoking a std::mem_fn.
        for more detail see the man website.

        member type:
            result_type
            argument_type
            first_argument_type
            second_argument_type

    --------------------------------------------
    1.3 bad_function_call:
        std::bad_function_call is the type of the exception thrown by std::function::operator()
        if the function wrapper has no target.

        member function:
            constructor

        Inherited from std::exception

    --------------------------------------------
    1.4 invoke (since c++17)

2. Bind
    2.1 bind
        The function template bind generates a call wrapper for f(argument)
        Calling this wrapper is equivalent to invoking of with some of its
        arguments bound to args(argument).

        return value:
        A function object of unspecified type T, for which std::is_bind_expression<T>::value == true.
        for more detail see the man website.

    --------------------------------------------
    2.2 is_bind_expression
        If T is type produced by a call to std::bind, this template is derived
        from std::true_type. For any other type, this template is derived from
        std::false_type.

        helper variable template
        template<class T>
        constexpr bool is_bind_expression_v = is_bind_expression<T>::value

    --------------------------------------------
    2.3 is_placeholder
        If T is type of a standard placeholder(_1, _2, ...) then this template is derived
        from std::integral_constant<int, 1>, std::integral_constant<int, 2> ... respectively
        If T is not a standard placeholder type, this template is derived from std::integral_constant<int, 0>.

    --------------------------------------------
    2.4 placeholder
        The std::placeholders namespace contains the placeholder object
        (_1, ..., _N) where N is an implementation defined maximum number.
        When used as an argument in a std::bind expression, the placeholder
        objects ar stored in the generated function object, and when that
        function object is invoked with unbound arguments, each placeholder _N
        is replaced by the corresponding Nth unbound argument.

3. Reference Wrapper
    3.1 reference_wrapper
        std::reference_wrapper is a class template that wraps a reference
        in a copyable, assignable object. It is frequently used as a mechanism
        to store reference inside standard containers (like: std::vector) which
        cannot normally hold reference.

    --------------------------------------------
    3.2 ref and cref
        Function template ref and cref are helper function that generate
        an object of type std::reference_wrapper, using template argument
        deduction to determine the template argument of type result.

4. Function objects (build-in)
    4.1 arithmetic  operations

    --------------------------------------------
    4.2 comparison  operations

    --------------------------------------------
    4.3 logical     operations

    --------------------------------------------
    4.4 bitwise     operations

    --------------------------------------------
    4.5 negators    operations


5. some deprecated function since c++11
    5.1 base

    --------------------------------------------
    5.2 binders
*/
