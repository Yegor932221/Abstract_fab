#ifndef UNIT_H
#define UNIT_H
#include <QString>
#include <QSharedPointer>

class Unit {
public:
    using Flags = unsigned int;

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
