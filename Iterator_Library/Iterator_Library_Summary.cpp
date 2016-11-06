/*
            Iterator Library Summary:
            *************************
Iterator library;
    The iterator library provides definitions for five of iterators as well as
    iterator traits, adapters, and utility function.

Iterator category:
    There are five (until c++17) six (since c++17) kinds of iterators:
        ContiguousIterator
        RandomAccessIterator
        BidirectionalIterator
        ForwardIterator
        OutputIterator
        and ContiguousIterator (since c++17).
    Instead of being defined by special types, each category of iterator is defined
    by the operations that can be performed on it. The definition means that any type
    that supports the necessary operations can be used as an iterator -- for example
    a pointer supports all of the operations required by RandomAccessIterator, so a
    pointer can be used anywhere a RandomAccessIterator is excepted.

    All of the iterator categories(except OutputIterator) can be organized into a hierarchy,
    where a more powerful iterator categories (e.g. RandomAccessIterator) support the operations
    of less powerful categories (e.g. InputIterator). If an iterator falls into one of these
    categories and also satisfies the requirement of OutputIterator, then it is called a
    mutable iterator and supports both input and output.

    Non-mutable iterators are called constant iterators.

    NoTe: ContiguousIterator category was only formally specified in c++17, but the iterator
    of std::vector, std::basic_string, std::array, and std::valarray, as well as pointers
    into C array are often treated as a separate category in per-c++17


Iterator primitive:
    iterator_traits                 provides uniform interface to the properties of an iterator
    input_iterator_tag              empty class types used to indicate iterator categories
    output_iterator_tag             also
    forward_iterator_tag            also
    bidirectional_iterator_tag      also
    random_access_iterator_tag      also
    iterator                        the basic iterator

Iterator adaptors
    reverse iterator:               iterator adaptors for reverse-order traversal
    make_reverse_iterator:          creates a std::reverse_iterator of type inferred form the argument
    move_iterator:                  iterator adaptor which dereferences to an r-value reference
    make_move_iterator:             creates a std::move_iterator of type inferred ( deduced ) from the argument
    back_insert_iterator:           iterator adaptor for insertion at the end of a container
    back_inserter:                  creates a std::back_insert_iterator of type inferred from the argument
    front_insert_iterator:          iterator adaptor for insertion at the front of a container
    front_inserter:                 creates a std::front_insert_iterator of type inferred form the argument
    insert_iterator:                iterator adaptor for insertion into a container
    inserter:                       create a std::insert_iterator of type inferred form the argument

Stream iterator
    istream_iterator:               input iterator that reads from std::basic_isteram
    ostream_iterator:               output iterator that writes to std::basic_ostream
    istreambuf_iterator:            input iterator that reads form std::basic_streambuf
    ostreambuf_iterator:            output iterator that writes to std::basic_streambut

Iterator operation:
    advance:                        advances an iterator by giving distance
    distance:                       returns the distance between two iterator
    next:                           increment an iterator
    prev:                           decrement an iterator

Range access
    Those non-member function provides a generic interface for containers, plain arrays, and std::initializer_list.

    begin:                          returns an iterator to the beginning of a container or array
    cbegin:                         same as begin but constant
    end:                            returns an iterator to the end of a container or array
    cend:                           same as end but constant
    rbegin:                         returns a reverse iterator to a container of array
    crbegin:                        same as rbegin but constant
    rend:                           returns a reverse end iterator to a container of array
    crend:                          same as rend but constant

Container access
    Those non-member function provides a generic interface for containers, plain arrays, and std::initializer_list.

    size:                           returns the size of a container or array
    empty:                          checks whether the container is empty
    data:                           obtains the pointer to the underlying array



*/
