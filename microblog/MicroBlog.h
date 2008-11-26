#ifndef MICROBLOG_H_
#define MICROBLOG_H_

#include <QObject>
#include <config.h>
#include <boost/shared_ptr.hpp>

class VISIBLE_SYM MicroBlog : public QObject
{
    Q_OBJECT
public:
    MicroBlog(bool init = true);
    ~MicroBlog();

    void init();

private:
    class Private;
    Private * const d;
};

typedef boost::shared_ptr<MicroBlog> MicroBlogPtr;

#endif //MICROBLOG_H_