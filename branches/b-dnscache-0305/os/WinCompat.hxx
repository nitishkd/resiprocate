#if !defined(resip_WinCompat_hxx)
#define resip_WinCompat_hxx

#ifdef WIN32
#include <Iphlpapi.h>
#endif

#include "resiprocate/os/BaseException.hxx"
#include "resiprocate/os/Mutex.hxx"
#include "resiprocate/os/Tuple.hxx"

namespace resip
{

class WinCompat
{
   public:
      //typedef enum Version
      // above is not valid C++ syntax
      enum Version
      {
         NotWindows,
         Windows95,
         Windows98,
         Windows98SE,
         WindowsME,
         WindowsNT,
         Windows2000,
         WindowsXP,
         Windows2003Server,
         WindowsUnknown
      };

      class Exception : public BaseException
      {
         public:
            Exception(const Data& msg, const Data& file, const int line);
            const char* name() const { return "TransportException"; }
      };

      static Version getVersion();
      static Tuple determineSourceInterface(const Tuple& destination);

   private:
      static WinCompat* mInstance;
      static WinCompat* instance();

      static Tuple WinCompat::determineSourceInterfaceWithIPv6(const Tuple& destination);
      static Tuple WinCompat::determineSourceInterfaceWithoutIPv6(const Tuple& destination);
      
      typedef DWORD (WINAPI * GetBestInterfaceExProc)(const sockaddr *, DWORD *);
      typedef DWORD (WINAPI * GetAdaptersAddressesProc)(ULONG, DWORD, VOID *, IP_ADAPTER_ADDRESSES *, ULONG *);

      WinCompat();

      GetBestInterfaceExProc getBestInterfaceEx;
      GetAdaptersAddressesProc getAdaptersAddresses;
      bool loadLibraryAlreadyFailed;

};

}

#endif
