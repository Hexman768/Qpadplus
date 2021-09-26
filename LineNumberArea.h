#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H

#include <QWidget>
#include <CodeEdit.h>

class LineNumberArea : public QWidget
{
    Q_OBJECT

public:
    LineNumberArea(CodeEdit *editor) : QWidget(editor)
    {
        codeEdit = editor;
    }

    QSize sizeHint() const Q_DECL_OVERRIDE
    {
        return QSize(codeEdit->getLineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE
    {
        codeEdit->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEdit *codeEdit;
};

#endif // LINENUMBERAREA_H
