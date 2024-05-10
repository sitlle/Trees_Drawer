#pragma once

namespace Control {
    class KeyBoard_Control {
    public:
        KeyBoard_Control() = default;

        ~KeyBoard_Control() = default;

        static void MOVE_UP() noexcept;

        static void MOVE_DOWN() noexcept;

        static void MOVE_LEFT() noexcept;

        static void MOVE_RIGHT() noexcept;

        static void DELETE() noexcept;
    };

    class Mouse_Control {
    public:
        Mouse_Control() = default;

        ~Mouse_Control() = default;

        static void MOVE_UP() noexcept;

        static void MOVE_DOWN() noexcept;
    };

    class Arrow_Control {
    public:
        Arrow_Control() = default;
        ~Arrow_Control() = default;

        static void MOVE_LEFT() noexcept;

        static void MOVE_RIGHT() noexcept;

        static void MOVE_UP() noexcept;

        static void MOVE_DOWN() noexcept;

    };

    class Nums_Control {
    public:
        Nums_Control() = default;
        ~Nums_Control() = default;

        static void NUM1() noexcept;

        static void NUM2() noexcept;

        static void NUM3() noexcept;

        static void NUM4() noexcept;
    };
};