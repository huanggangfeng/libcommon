#include <unistd.h>
#include "common/platform.h"
#include "common/socket.h"

#if defined(PLATFORM_POSIX)
#include <sys/socket.h>
#endif

PRIVATE ssize_t socket_write(socket_t *s, const void *buf, size_t len)
{
    if (s == NULL) {
        errno = EINVAL;
        return -1;
    }
#if defined(MSG_NOSIGNAL)
    return send(s->fd, buf, len, MSG_NOSIGNAL);
#else
    return write(s->fd, buf, len);
#endif
}
