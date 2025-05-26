#ifndef UNIT_H
#define UNIT_H
#include <QString>
#include <QSharedPointer>

class Unit {
public:
    using Flags = unsigned int;
    enum AccessModifier
    {
        PUBLIC=1,
        PROTECTED=1<<1,
        PRIVATE=1<<2,
        PRIVATEPROTECTED=1<<3,
        FILE=1<<4,
        INTERNAL=1<<5,
        PROTECTEDINTERNAL=1<<6,
    };
public:
    virtual ~Unit() = default;

    virtual void add( const QSharedPointer< Unit >& , Flags )
    {
        throw std::runtime_error( "Not supported" );
    }

    virtual QString compile( unsigned int level = 0 ) const = 0;

protected:
    virtual QString generateShift( unsigned int level ) const
    {
        static const auto DEFAULT_SHIFT = " ";
        QString result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};
#endif // UNIT_H
