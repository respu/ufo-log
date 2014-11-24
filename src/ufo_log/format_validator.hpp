/*
 * format_validator.hpp
 *
 *  Created on: Nov 24, 2014
 *      Author: rafa
 */

#ifndef UFO_LOG_FORMAT_VALIDATOR_HPP_
#define UFO_LOG_FORMAT_VALIDATOR_HPP_

#include <ufo_log/util/integer>

namespace ufo {

struct fmt_validator
{
private:
    //--------------------------------------------------------------------------
    class literal
    {
    public:
        //----------------------------------------------------------------------
        struct index_out_of_range {};
        //----------------------------------------------------------------------
        template <uword N>
        constexpr literal (const char(&arr)[N]) :
            m_lit  (arr),
            m_size (N - 1)
        {
            static_assert( N >= 1, "not a string literal");
        }
        //----------------------------------------------------------------------
        constexpr operator const char *()   { return m_lit;  }
        constexpr uword size()              { return m_size; }
        constexpr char operator[] (uword i) { return in_range (i) | m_lit[i]; }
        //----------------------------------------------------------------------
    private:
        //----------------------------------------------------------------------
        constexpr char in_range (uword i)
        {
            return (i < size()) ? 0 : throw index_out_of_range();
        }
        //----------------------------------------------------------------------
        const char *const m_lit;
        uword          m_size;
        //----------------------------------------------------------------------
    };
    //--------------------------------------------------------------------------
    static constexpr word validate_consume_param(
                            uword i, word arity, literal l
                            )
    {
        return -(arity + 1);
    }
    //--------------------------------------------------------------------------
    template <class T, class... Args>
    static constexpr word validate_consume_param(
                            uword i, word arity, literal l, T p, Args ...args
                            )
    {
        return validate (i + 2, arity + 1, l, args...);
    }
    //--------------------------------------------------------------------------
    static constexpr word validate_consume_param_with_fmt(
                            uword i, word arity, literal l
                            )
    {
        return -(arity + 1);
    }
    //--------------------------------------------------------------------------
    template <class T, class... Args>
    static constexpr word validate_consume_param_with_fmt(
                            uword i, word arity, literal l, T p, Args ...args
                            )
    {
        return validate (i + 3, arity + 1, l, args...);
    }
    //--------------------------------------------------------------------------
    static constexpr bool token_with_fmt (uword i, literal l)
    {
        return (i <= (l.size() - 3)) && (l[i] == '{') && (l[i + 2] == '}');
    }
    //--------------------------------------------------------------------------
    static constexpr bool token_with_no_fmt (uword i, literal l)
    {
        return (i <= (l.size() - 2)) && (l[i] == '{') && (l[i + 1] == '}');
    }
    //--------------------------------------------------------------------------
    static constexpr bool finished (uword i, literal l)
    {
        return i == (l.size() - 1);
    }
    //--------------------------------------------------------------------------
    template <class... Args>
    static constexpr word check_no_remaining(
                            word arity, literal l, Args ...args
                            )
    {
        return -(arity + 1);
    }
    //--------------------------------------------------------------------------
    static constexpr word check_no_remaining (word arity, literal l)
    {
        return arity;
    }
    //--------------------------------------------------------------------------
public:
    //--------------------------------------------------------------------------
    template <class... Args>
    static constexpr word validate(
                uword i, word arity, literal l,  Args ...args
                )
    {
        return (last_char (i, l)) ?
                    check_no_remaining (arity, l, args...) :
               (token_with_fmt (i, l)) ?
                   validate_consume_param_with_fmt (i, arity, l, args...) :
               (token_with_no_fmt (i, l)) ?
                   validate_consume_param (i, arity, l, args...) :
                   validate (i + 1, arity, l, args...);
    }
}; //validator
//------------------------------------------------------------------------------
template <uword N, class... Args>
constexpr word valid_fmt (const char (&arr)[N], Args ...args)                    //negative values = param error, 0 or positive = arity
{
    static_assert( N >= 1, "not a string literal");
    return fmt_validator::validate (0, 0, arr, args...);
}
//------------------------------------------------------------------------------

} //ufo

#endif /* UFO_LOG_FORMAT_VALIDATOR_HPP_ */
