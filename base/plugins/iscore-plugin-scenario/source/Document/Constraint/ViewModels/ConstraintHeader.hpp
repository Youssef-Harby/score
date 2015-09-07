#pragma once
#include <QGraphicsObject>
#include <QFont>

class ConstraintView;
class ConstraintHeader : public QGraphicsObject
{
    public:
        enum class State {
            Hidden, // No rack, we show nothing
            RackHidden, // There is at least a hidden rack in the constraint
            RackShown // There is a rack currently shown
        };

        using QGraphicsObject::QGraphicsObject;
        static constexpr int headerHeight() { return 25; }
        static const QFont font;

        void setWidth(double width);
        void setText(const QString &text);

        void setState(State s)
        {
            if(s == m_state)
                return;

            if(m_state == State::Hidden)
                show();
            else if(s == State::Hidden)
                hide();

            m_state = s;
            update();
        }

    protected:
        State m_state{};
        double m_width{};
        QString m_text;
};
