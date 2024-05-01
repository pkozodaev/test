#pragma once

#include "../log_facade/log_facade.h"

#include <string>


class _static
{
public:
    static void write( std::string&& _data )
    {
        static const logger& _logger = logger_instance();

        _logger.write( std::move( _data ) );
    }

    static const logger& logger_instance()
    {

        static const logger& _logger = facade::get_logger();

        return _logger;
    }
};


struct llog : _static {};