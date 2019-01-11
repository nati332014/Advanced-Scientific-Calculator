#ifndef TOKENIZER_H
#define TOKENIZER_H

using namespace std;

class tokenizer
{
    public:
        tokenizer();


bool isOperator(char token);

    protected:
enum state
{
    NONE = 0,
    NUM,
    DEC,
    NEG,
    OPR,
    UNDIF,
    BLANK
};

 int finiteTable[7][7] = {{0, NUM,  DEC, NEG, OPR,  UNDIF,  BLANK},
/* STATE 1 */   {NUM,  NUM,  DEC,   NONE,  NONE,   NONE,  NONE},
/* STATE 2 */   {DEC,       DEC,  NONE,  NONE,  NONE,   NONE,  NONE},
/* STATE 3 */   {NEG, NUM,  DEC,   NONE,  NONE,   NONE,  NONE},
/* STATE 4 */   {OPR,  NONE, NONE,  NONE,  NONE,   NONE,  NONE},
/* STATE 5 */   {UNDIF,   NONE, NONE,  NONE,  NONE,   UNDIF, NONE},
/* STATE 6 */   {BLANK,     NONE, NONE,  NONE,  NONE,   NONE,  NONE}};

    private:
};

#endif // TOKENIZER_H
