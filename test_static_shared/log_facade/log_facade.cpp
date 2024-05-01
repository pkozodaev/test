#include "log_facade.h"


wr_fn_t facade::m_wr_fn;
//std::mutex facade::m_mutex;
std::shared_ptr<logger> facade::m_logger;
pvk_debug<facade::static_member> facade::pvk_debug_;


class impl {
private:
    impl() {}

public:
    impl(const impl& ) = delete;
    impl(impl&&) = delete;
    impl& operator=(const impl&) = delete;
    impl& operator=(impl&&) = delete;
    static impl& instance() {
        static impl m_impl;
        return m_impl;
    }

    void register_log_provider( const wr_fn_t& writer) {
        m_wr_fn = writer;
        if( m_logger ) {
            m_logger->function_ = m_wr_fn;
        }
    }

    const logger &get_logger() {
        auto _logger = std::make_shared< logger >();

        _logger->function_ = m_wr_fn;

        m_logger = _logger;

        return *_logger;
    }

private:
    wr_fn_t m_wr_fn;
    std::shared_ptr<logger> m_logger;
    struct singleton_member{};
    pvk_debug<singleton_member>   pvk_debug_;
};

void facade::register_log_provider(const wr_fn_t &writer) {
    auto& _impl = impl::instance();
    _impl.register_log_provider(writer);
}

const logger &facade::get_logger() {
    auto& _impl = impl::instance();
    return _impl.get_logger();
}
