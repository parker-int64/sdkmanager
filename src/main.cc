#include "webview/webview.h"
#include <iostream>

#ifdef _WIN32
#include "platform/win/resource.h"
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE /*hPrevInst*/,
                   LPSTR /*lpCmdLine*/, int /*nCmdShow*/)
{
#else
int main()
{
#endif
        try
        {
#ifdef _DEBUG
                webview::webview w(true, nullptr); // Disable debug tool
#else
                webview::webview w(false, nullptr);
#endif
                w.set_title("Seeed JetPack Imager");
                w.set_size(800, 600, WEBVIEW_HINT_NONE);
                w.set_size(800, 600, WEBVIEW_HINT_MIN);

#ifdef _WIN32
                auto result = w.window().value();

                HICON hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));

                HWND hwnd = reinterpret_cast<HWND>(result);

                if (hIcon)
                {
                        SetClassLongPtr(hwnd, GCLP_HICON, (LONG_PTR)hIcon);
                        SetClassLongPtr(hwnd, GCLP_HICONSM, (LONG_PTR)hIcon);
                }
                else
                {
                        std::cerr << "Failed to load icon" << std::endl;
                }
#endif

#ifdef _DEBUG
                // Disable the context menu
                w.navigate("http://localhost:5173");
#else
#endif
                // Run webview
                w.run();
        }
        catch (const webview::exception &e)
        {
                std::cerr << e.what() << '\n';
                return 1;
        }

        return 0;
}
