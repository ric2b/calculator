// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

namespace CalculatorApp
{
public
    ref class WindowFrameService sealed
    {
    public:
        internal :
            // createdByUs means any window that we create.
            // !createdByUs means the main window
            static WindowFrameService
            ^ CreateNewWindowFrameService(bool createdByUs, Platform::WeakReference parent);

        int GetViewId();

        concurrency::task<void> HandleViewRelease();

    private:
        WindowFrameService(Platform::WeakReference parent);
        void InitializeFrameService(bool createdByUs);

        void
        OnConsolidated(_In_ Windows::UI::ViewManagement::ApplicationView ^ sender, _In_ Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs ^ e);
        void OnClosed(_In_ Windows::UI::Core::CoreWindow ^ sender, _In_ Windows::UI::Core::CoreWindowEventArgs ^ args);

    private:
        Platform::Agile<Windows::UI::Core::CoreWindow ^> m_currentWindow;
        Platform::Agile<Windows::UI::Core::CoreDispatcher ^> m_coreDispatcher;
        int m_viewId;
        Platform::WeakReference m_parent;
    };
}
