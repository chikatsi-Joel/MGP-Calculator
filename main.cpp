#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QWidget>
#include<QTableWidget>
#include<QTableView>
#include<QTableWidgetItem>
#include<QLabel>
#include<QStandardItemModel>
#include<QGridLayout>
#include<QStandardItem>
#include<QStackedWidget>
#include <QTranslator>

struct UE{
    int _niveau;
    std::vector<std::string> _data;
    UE(int niveau){
        _niveau=niveau;
        _data={"INF"+std::to_string(niveau)+"11  ", "INF"+std::to_string(niveau)+"21  ", "INF"+std::to_string(niveau)+"31  ","MATH"+std::to_string(niveau)+"11  ","UE_OP_S1","INF"+std::to_string(niveau)+"12  ","INF"+std::to_string(niveau)+"22","INF"+std::to_string(niveau)+"32  ","MATH"+std::to_string(niveau)+"12  ","UE_OP_S2", "LANG    "};
    }
};
std::pair<float, std::string> Appreciate(float note){

    if(note<35)
        return std::make_pair(0, "E");
    else if(note<40)
        return std::make_pair(1, "D-");
    else if(note<45)
        return std::make_pair(1.3, "D");
    else if(note<50)
        return std::make_pair(1.7, "D+");
    else if(note<55)
        return std::make_pair(2, "C-");
    else if(note<60)
        return std::make_pair(2.3, "C");
    else if(note<65)
        return std::make_pair(2.7, "B");
    else if(note<70)
        return std::make_pair(3, "B+");
    else if(note<75)
        return std::make_pair(3.3, "A-");
    else if(note<80)
        return std::make_pair(3.7, "A");
    else if(note<100)
        return std::make_pair(4, "A+");
    return std::make_pair(0, "");
}
class School : public QMainWindow{
public:
    School(int niv, QWidget* parent=nullptr) : QMainWindow(parent){

        central=new QWidget(this);
        star_lay=new QHBoxLayout(nullptr);
        star=new QPushButton("Statistique", nullptr);
        star->hide();
        table=new QTableView(central);
        box_v_mat=new QVBoxLayout(nullptr);
        emettre= new QPushButton("Soumettre",nullptr);
        emettre->setMinimumWidth(350);
        title=new QLabel("Gradi Joel");
        title->setMinimumHeight(90);
        model=new QStandardItemModel(table);
        pseudo_result=new QLabel("",nullptr);
        box_v=new QVBoxLayout(central);
        box_h=new QHBoxLayout(nullptr);
        stat=new QPushButton(nullptr);
        title->setAlignment(Qt::AlignTop);

        arr=new QPushButton("back");
        emettre->setMaximumWidth(200);
        emettre->setMouseTracking(true);
        man=new QPushButton(nullptr);
        result=new QLabel("",central);
        title->setAlignment(Qt::AlignCenter);
        title->setFont(QFont("Ubuntu", 17, QFont::Bold));
        note=new QHBoxLayout(nullptr);
        grid_note=new QGridLayout(nullptr);

        result->setMargin(80);
        e=new UE(niv);
        for(std::string &val : e->_data)
            box_v_mat->addWidget(new QLabel(QString::fromStdString(val)));

        for(std::size_t i=0; i<e->_data.size(); i++)
            line_.push_back(new QLineEdit());
        for(std::size_t i=0; i<e->_data.size(); i++)
            line_[i]->setText("6");

        for(std::size_t i=0; i<e->_data.size(); i++)
            line_note.push_back(new QLineEdit());

        for(std::size_t i=0; i<e->_data.size(); i++)
            line_note[i]->setText("89");

        for(std::size_t i=0; i<e->_data.size(); i++){
            grid_note->addWidget(line_note[i], i, 0);
            grid_note->addWidget(line_[i], i, 1);
        }
        for(std::size_t i=0; i<e->_data.size(); i++)
            grid_note->setColumnStretch(i, 5);


        for(std::size_t i=0; i<e->_data.size(); i++)
            grid_note->setColumnStretch(i, 5);

        box_v->addWidget(title);
        box_h->addLayout(box_v_mat);
        box_h->addLayout(grid_note);
        box_h->addWidget(pseudo_result);
        box_h->setSpacing(20);
        box_v->addLayout(box_h);

        star_lay->addWidget(result);
        star_lay->addWidget(star);
        box_v->addLayout(star_lay);
        box_h->setAlignment(this, Qt::AlignBottom);
        box_v->addWidget(emettre);
        box_h->addWidget(table);
        model->setHorizontalHeaderLabels({" U E ", "Notes /100", "Appreciation", "MGP", "Credits", "Total"});

        table->setMinimumWidth(1200);
        table->setMaximumHeight(700);

        connect(emettre, &QPushButton::clicked, this, &School::updateTable);
        connect(star, &QPushButton::clicked, this, &School::statis);
        note->setAlignment(central, Qt::AlignLeft);
        note->setMargin(80);

        setMaximumHeight(700);
        setStyleSheet("QWidget {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #AB7AEC, stop:1 #190720);}"
                      "QMainWindow {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #AB7AEC, stop:1 #190720);");
        setStyleSheet("QPushButton { background-color: #240655; color: white; border-radius: 20px; border: none; padding: 10px 20px; margin-bottom : 90px;} "
                      "QPushButton:hover {background-color: #3e8e41;}"
                      "QLineEdit { background-color: #D5C6EF; color: #221951; border-radius: 20px; border: none; padding: 10px 20px;}");
        setCentralWidget(central);
    }
private:
    QWidget* central;
    QHBoxLayout* star_lay;
    QGridLayout* grid_note;
    std::vector<QLineEdit*> line_note;
    std::vector<QLineEdit*> line_;
    QLabel* title;
    QLabel* result;
    QTableView* table;
    QTableWidget* tab_wid;
    UE* e;
    QPushButton* arr;
    QPushButton* emettre;
    QVBoxLayout* box_v_mat;
    QPushButton* man;
    QPushButton* stat;
    QPushButton* star;
    QVBoxLayout* box_v;
    QLabel* pseudo_result;
    QStandardItemModel* model;
    QHBoxLayout* note;
    QHBoxLayout* box_h;
private slots:
    void updateTable()
        {
            star->show();
            std::vector<std::pair<std::string, std::pair<float, int>>> energ;
            model->setHorizontalHeaderLabels({" U E ", "Notes /100", "Appreciation", "MGP", "Credits", "Total"});
            for(std::size_t i=0; i<e->_data.size(); i++)
                energ.push_back(std::make_pair(e->_data[i], std::make_pair(line_note[i]->text().toFloat(), line_[i]->text().toInt())));

            model->removeRows(0, model->rowCount());
            for(std::size_t i=0; i<e->_data.size(); i++)
                model->appendRow({new QStandardItem(QString::fromStdString(energ[i].first)), new QStandardItem(QString::number(energ[i].second.first)), new QStandardItem(QString::fromStdString(Appreciate(energ[i].second.first).second)), new QStandardItem(QString::number(Appreciate(energ[i].second.first).first)), new QStandardItem(QString::number(energ[i].second.second)), new QStandardItem(QString::number(energ[i].second.second*Appreciate(energ[i].second.first).first))});
            table->setModel(model);

            float som=0;
            for(std::size_t i=0; i<energ.size(); i++)
                som+=energ[i].second.second*Appreciate(energ[i].second.first).first;
            double moy=som/std::accumulate(energ.begin(), energ.end(), 0, [=](double acc, std::pair<std::string, std::pair<float, int>>val){
                return acc + val.second.second;
            });
            if(moy<3 && moy>=2){
                pseudo_result->setText("  MGP : "+QString::fromStdString(std::to_string(moy).substr(0, 4)));
                pseudo_result->setStyleSheet("color : green;");
                result->setText("Vous Avez réussie Félicitation à vous;..");
                result->setFont(QFont("Ubuntu", 13, QFont::Bold));
                pseudo_result->setFont(QFont("Ubuntu", 13, QFont::Bold));
                result->setStyleSheet("color: green;");
            }
            if(moy>=3){
                pseudo_result->setText("Resultat : "+QString::fromStdString(std::to_string(moy).substr(0, 4)));
                pseudo_result->setStyleSheet("color : green;");
                result->setText("Vous Avez réussie Avec Excellence Bravo à vous Champion;..");
                result->setFont(QFont("Ubuntu", 13, QFont::Bold));
                pseudo_result->setFont(QFont("Ubuntu", 13, QFont::Bold));
                result->setStyleSheet("color: green;");
            }
    }
public slots:
    void statis(){
        central->hide();
    }

};

class Main : public QMainWindow{
public:
    Main(QWidget* parent=nullptr) : QMainWindow(parent){

        center=new QWidget(this);
        send=new QPushButton("Envoyer");
        niveau_edit=new QLineEdit(nullptr);
        bienvenue=new QLabel("Bienvenue Dans Notre Application");
        bienvenue->setFont(QFont("Ubtuntu", 17, QFont::Bold));
        niveau_lab=new QLabel("Niveau : ");
        box_h=new QHBoxLayout(nullptr);
        box_v=new QVBoxLayout(center);
        stack_wid=new QStackedWidget(center);



        connect(send, &QPushButton::clicked, [=](){
            int niv=std::stoi(niveau_edit->text().toStdString());
            School* sc=new School(niv);
            sc->show();
            destroy();
        });

        box_v->addWidget(bienvenue);
        box_v->addLayout(box_h);
        box_v->addWidget(send);
        box_v->setSpacing(78);
        box_v->addWidget(stack_wid);
        box_v->setMargin(90);
        box_h->addWidget(niveau_lab);
        box_h->addWidget(niveau_edit);

        setCentralWidget(center);
        setStyleSheet("QPushButton { background-color: #240655; color: white; border-radius: 20px; border: none; padding: 10px 20px; margin-bottom : 90px;} "
                      "QLineEdit { background-color: #D5C6EF; color: #221951; border-radius: 20px; border: none; padding: 10px 20px;}");
    }
private:
    QPushButton* send;
    QLineEdit* niveau_edit;
    QWidget* center;
    QLabel* bienvenue;
    QHBoxLayout* box_h;
    QVBoxLayout* box_v;
    QLabel* niveau_lab;
    QStackedWidget* stack_wid;
};

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Main *w=new Main(nullptr);
    w->show();
    return app.exec();
}
