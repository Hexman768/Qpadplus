#ifndef CODEEDIT_H
#define CODEEDIT_H

#include <QTextEdit>

class CodeEdit : public QTextEdit
{
    Q_OBJECT
public:
    CodeEdit(QWidget *parent = nullptr);

    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int getLineNumberAreaWidth();

public:
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private slots:

    void updateLineNumberAreaWidth(int newBlockCount);
    void updateLineNumberArea(QRectF /*rect_f*/);
    void updateLineNumberArea(int /*slider_pos*/);
    void updateLineNumberArea();
    void highlightCurrentLine();

private:
    QWidget *lineNumberArea;
    int getFirstVisibleBlockId();
};

#endif // CODEEDIT_H
