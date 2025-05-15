#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H


class CSharpPrintOperatorUnit
{
public:
    explicit CSharpPrintOperatorUnit( const QString& text );
    QString compile( unsigned int level = 0 ) const ;
private:
    QString m_text;
};

#endif // CSHARPPRINTOPERATORUNIT_H
