﻿#pragma once

#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.Xaml.Markup.h"
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.Controls.Primitives.h"
#include "BlankUserControl.g.h"

namespace winrt::RuntimeComponent1::implementation
{
    struct BlankUserControl : BlankUserControlT<BlankUserControl>
    {
        BlankUserControl();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

        static winrt::Windows::UI::Xaml::DependencyProperty MyPropertyProperty();

        winrt::event_token Happened(Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const
          & handler) noexcept;
        void Happened(winrt::event_token const& token);


    private:
      static winrt::Windows::UI::Xaml::DependencyProperty m_myPropertyProperty;
      winrt::event<Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable>> m_happened;

    };
}

namespace winrt::RuntimeComponent1::factory_implementation
{
    struct BlankUserControl : BlankUserControlT<BlankUserControl, implementation::BlankUserControl>
    {
    };
}
