QDomDocument doc;

doc.setContent(QString("<root><elem someAttr='attrValue'><subElem1 /><subElem2 /></elem></root>"), (QString*) 0, (int*) 0, (int*) 0);

QXmlQuery q(QXmlQuery::XQuery10);

QDomNodeModel m(q.namePool(), doc);

q.setFocus(QXmlItem(m.fromDomNode(doc.documentElement())));

q.setQuery("elem/@someAttr");

QXmlResultItems res;
q.evaluateTo(&res);

while (!res.next().isNull())
{
	QDomElement elem = m.toDomNode(res.current().toNodeModelIndex()).toElement();
	qDebug() << m.toDomNode(res.current().toNodeModelIndex()).toAttr().value();
}
