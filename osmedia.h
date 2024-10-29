#pragma once
#include "incontrol.h"
#ifdef _WIN32
    #include <guiddef.h>
    #include <winrt/Windows.Media.Control.h>
    #include <winrt/Windows.Storage.Streams.h>
    using namespace winrt::Windows::Media::Control;
    using namespace winrt::Windows::Storage::Streams;
#endif


class OSMedia{
public:
OSMedia();

private:
};

inline OSMedia::OSMedia(){
    winrt::init_apartment();
    try {auto Session = GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();}
    catch (const winrt::hresult_error e) {std::cout << "Error: " << e.code() << std::endl;}
}
