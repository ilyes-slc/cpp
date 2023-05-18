#ifndef ARTICLE_H
#define ARTICLE_H

using namespace std;

class Article
{
    public:
        Article();
        virtual ~Article();

        string Getreference() { return reference; }
        void Setreference(string val) { reference = val; }
        string Getdesignation() { return designation; }
        void Setdesignation(string val) { designation = val; }
        float GetprixBase() { return prixBase; }
        void SetprixBase(float val) { prixBase = val; }
        void operator+=(const Article& other)
            {
                basePrice += other.basePrice;
            }

    protected:

    private:
        string reference;
        string designation;
        float prixBase;
};

#endif // ARTICLE_H
