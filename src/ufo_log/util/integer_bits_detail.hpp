/*
 * integer_bytes_detail.hpp
 *
 *  Created on: Sep 5, 2013
 *      Author: rafgag
 */

#ifndef INTEGER_BYTES_DETAIL_HPP_
#define INTEGER_BYTES_DETAIL_HPP_

namespace ufo { namespace detail {

template<class T, unsigned bytes = sizeof (T)>
struct byte_array_write
{};

template<>
struct byte_array_write<uint16_t, 2>
{
    static inline void little_endian (uint8_t* out, uint16_t val)
    {
        byte_array_write_le_16 (out, val);
    };

    static inline void big_endian (uint8_t* out, uint16_t val)
    {
        byte_array_write_be_16 (out, val);
    };
};

template<>
struct byte_array_write<uint32_t, 3>
{
    static inline void little_endian (uint8_t* out, uint32_t val)
    {
        byte_array_write_le_24 (out, val);
    };

    static inline void big_endian (uint8_t* out, uint32_t val)
    {
        byte_array_write_be_24 (out, val);
    };
};

template<>
struct byte_array_write<uint32_t, 4>
{
    static inline void little_endian (uint8_t* out, uint32_t val)
    {
        byte_array_write_le_32 (out, val);
    };

    static inline void big_endian (uint8_t* out, uint32_t val)
    {
        byte_array_write_be_32 (out, val);
    };
};

template<>
struct byte_array_write<uint64_t, 5>
{
    static inline void little_endian (uint8_t* out, uint64_t val)
    {
        byte_array_write_le_40 (out, val);
    };

    static inline void big_endian (uint8_t* out, uint64_t val)
    {
        byte_array_write_be_40 (out, val);
    };
};

template<>
struct byte_array_write<uint64_t, 6>
{
    static inline void little_endian (uint8_t* out, uint64_t val)
    {
        byte_array_write_le_48 (out, val);
    };

    static inline void big_endian (uint8_t* out, uint64_t val)
    {
        byte_array_write_be_48 (out, val);
    };
};

template<>
struct byte_array_write<uint64_t, 7>
{
    static inline void little_endian (uint8_t* out, uint64_t val)
    {
        byte_array_write_le_56 (out, val);
    };

    static inline void big_endian (uint8_t* out, uint64_t val)
    {
        byte_array_write_be_56 (out, val);
    };
};

template<>
struct byte_array_write<uint64_t, 8>
{
    static inline void little_endian (uint8_t* out, uint64_t val)
    {
        byte_array_write_le_64 (out, val);
    };

    static inline void big_endian (uint8_t* out, uint64_t val)
    {
        byte_array_write_be_64 (out, val);
    };

};

template<unsigned bytes>
struct byte_array_read
{};

template<>
struct byte_array_read<2>
{
    typedef uint16_t uint_return_type;
    static inline uint16_t little_endian (const uint8_t* in)
    {
        return byte_array_read_le_16 (in);
    };

    static inline uint16_t big_endian (const uint8_t* in)
    {
        return byte_array_read_be_16 (in);
    };
};

template<>
struct byte_array_read<3>
{
    typedef uint32_t uint_return_type;
    static inline uint32_t little_endian (const uint8_t* in)
    {
        return byte_array_read_le_24 (in);
    };

    static inline uint32_t big_endian (const uint8_t* in)
    {
        return byte_array_read_be_24 (in);
    };
};

template<>
struct byte_array_read<4>
{
    typedef uint32_t uint_return_type;
    static inline uint32_t little_endian (const uint8_t* in)
    {
        return byte_array_read_le_32 (in);
    };

    static inline uint32_t big_endian (const uint8_t* in)
    {
        return byte_array_read_be_32 (in);
    };
};

template<>
struct byte_array_read<5>
{
    typedef uint64_t uint_return_type;
    static inline uint64_t little_endian (const uint8_t* in)
    {
        return byte_array_read_le_40 (in);
    };

    static inline uint64_t big_endian (const uint8_t* in)
    {
        return byte_array_read_be_40 (in);
    };
};

template<>
struct byte_array_read<6>
{
    typedef uint64_t uint_return_type;
    static inline uint64_t little_endian (const uint8_t* in)
    {
        return byte_array_read_le_48 (in);
    };

    static inline uint64_t big_endian (const uint8_t* in)
    {
        return byte_array_read_be_48 (in);
    };
};

template<>
struct byte_array_read<7>
{
    typedef uint64_t uint_return_type;
    static inline uint64_t little_endian (const uint8_t* in)
    {
        return byte_array_read_le_56 (in);
    };

    static inline uint64_t big_endian (const uint8_t* in)
    {
        return byte_array_read_be_56 (in);
    };
};

template<>
struct byte_array_read<8>
{
    typedef uint64_t uint_return_type;
    static inline uint64_t little_endian (const uint8_t* in)
    {
        return byte_array_read_le_64 (in);
    };

    static inline uint64_t big_endian (const uint8_t* in)
    {
        return byte_array_read_be_64 (in);
    };
};

}} //namespaces

#endif /* INTEGER_BYTES_DETAIL_HPP_ */
