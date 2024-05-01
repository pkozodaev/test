#pragma once

#include <functional>
#include <string>
#include <iostream>
#include <memory>
#include <mutex>

using wr_fn_t = std::function< void(const std::string&)>;


class logger
{
public:
    inline void write( std::string&& _data ) const
    {
        function_( std::move( _data ) );
    }

    friend class facade;
    friend class impl;

protected:

    wr_fn_t function_;
};



// todo pvk debug
template<typename T>
struct pvk_debug {
    pvk_debug() { std::cout << "pvk debug> " << typeid(T).name() << " pvk_debug( " << std::hex << this << " ) ctor" << std::endl; }
    ~pvk_debug() { std::cout << "pvk debug> " << typeid(T).name() << " pvk_debug( " << std::hex << this << " ) dtor" << std::endl; }
};

class impl;

class facade {
public:
//    static void register_log_provider( const wr_fn_t& writer) {
//        m_wr_fn = writer;
//        if( m_logger ) {
//            m_logger->function_ = m_wr_fn;
//        }
//    }
//
//    static const logger &get_logger() {
//        auto _logger = std::make_shared< logger >();
//
//        _logger->function_ = m_wr_fn;
//
//        m_logger = _logger;
//
//        return *_logger;
//    }

    static void register_log_provider( const wr_fn_t& writer);

    static const logger &get_logger();

private:
    static wr_fn_t m_wr_fn;
//    static std::mutex m_mutex;
    static std::shared_ptr<logger> m_logger;
    struct static_member{};
    static pvk_debug<static_member>   pvk_debug_;
};


