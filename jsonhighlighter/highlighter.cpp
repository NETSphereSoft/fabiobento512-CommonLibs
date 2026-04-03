#include "highlighter.h"
#include <QRegularExpression>
#include <QTextCharFormat>
#include <QTextDocument>

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    //numbers
    rule.pattern = QRegularExpression("([-0-9.]+)(?!([^\"]*\"[\\s]*\\:))");
    rule.format.setForeground(QColor(255,192,85));
    rules.append(rule);

    //key
    rule.pattern = QRegularExpression("(\"[^\"]*\")");
    rule.format.setForeground(QColor(145,145,192));
    rules.append(rule);

    //value
    rule.pattern = QRegularExpression(":\\s*([\"](?:[^\"])*[\"])");
    rule.format.setForeground(QColor(145,145,192));
    rules.append(rule);

    //reserved words
    rule.pattern = QRegularExpression("(true|false|null)(?!\"[^\"]*\")");
    rule.format.setForeground(QColor(0,0,255));
    rules.append(rule);
}

void Highlighter::highlightBlock(const QString &text)
{
    for (const HighlightingRule &rule : rules) {
        QRegularExpressionMatchIterator it = rule.pattern.globalMatch(text);

        while (it.hasNext()) {
            QRegularExpressionMatch match = it.next();
            if (match.hasMatch()) {
                int start = match.capturedStart(1);
                int length = match.capturedLength(1);
                setFormat(start, length, rule.format);
            }
        }
    }
}