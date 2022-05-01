#ifndef T100VPCCALLBACK_H
#define T100VPCCALLBACK_H


class T100VPCCallback
{
    public:
        T100VPCCallback();
        virtual ~T100VPCCallback();

        static void         start(void*, void*);
        static void         stop(void*, void*);
        static void         quit(void*, void*);

        static void         close(void*, void*);

        static void         setup(void*, void*);

        //
        static void         stop();
        static void         close();

        static bool         callback_start(void*, void*, void*, void*);
        static bool         callback_stop(void*, void*, void*, void*);
        static bool         callback_done(void*, void*, void*, void*);

        static bool         callback_debug(void*, void*, void*, void*);
        static bool         callback_debug_update(void*, void*, void*, void*);
        static bool         callback_debug_rom_base_update(void*, void*, void*, void*);
        static bool         callback_debug_ram_base_update(void*, void*, void*, void*);
        static bool         callback_debug_device_update(void*, void*, void*, void*);
        static bool         callback_debug_block_base_update(void*, void*, void*, void*);
        static bool         callback_debug_page_base_update(void*, void*, void*, void*);

        /*

        static void start(wxWindow*, void*);
        static void stop(wxWindow*, void*);
        static void quit(wxWindow*, void*);

        static void exit(wxWindow*, void*);
        static void exit();
        static void stop();

        static void timeout(void*);

        static void close(void*);
        static void close();
        */



    protected:

    private:
        static void*        m_frame;
        static void*        m_serve;
};

#endif // T100VPCCALLBACK_H
