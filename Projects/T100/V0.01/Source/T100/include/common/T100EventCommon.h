#ifndef T100EVENTCOMMON_H
#define T100EVENTCOMMON_H


//Common    10000 ~ 19999

enum{
    T100LOG_EVENT_ID_THREAD_OUTLINE                 = 10000,
    T100LOG_EVENT_ID_FRAME_CLOSE
};

//Custom    >=20000
enum{
    EVENT_ID_MAX                                    = 20000
};

#endif // T100EVENTCOMMON_H
