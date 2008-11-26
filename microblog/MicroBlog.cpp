#include "MicroBlog.h"
#include "PluginLoader.h"
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<MicroBlogEngine::PluginLoader> PluginLoaderPtr;

class MicroBlog::Private
{
public:
    Private() {}
    ~Private() {}

    void init();

    PluginLoaderPtr m_loader;
};

void MicroBlog::Private::init()
{
    if(!m_loader)
        m_loader = PluginLoaderPtr(new MicroBlogEngine::PluginLoader());

    m_loader->scanDisk();
}

MicroBlog::MicroBlog(bool init /*= true*/)
: d(new Private)
{
    d->init();
}

MicroBlog::~MicroBlog()
{

}

void MicroBlog::init()
{
    d->init();
}

#include "microblog.moc"
