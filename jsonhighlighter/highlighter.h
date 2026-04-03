#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QRegularExpression>
#include <QSyntaxHighlighter>
#include <QTextCharFormat>

// Downloaded from here:
// https://github.com/isomoar/json-editor/blob/master/syntaxhighlightening/highlighter.cpp

class Highlighter: public QSyntaxHighlighter
{
	Q_OBJECT
public:
     Highlighter(QTextDocument *parent = 0);
protected:
     struct HighlightingRule
     {
         QRegularExpression pattern;
         QTextCharFormat format;
     };
     QVector<HighlightingRule> rules;


protected:
    void highlightBlock(const QString &text);
};

#endif // HIGHLIGHTER_H
