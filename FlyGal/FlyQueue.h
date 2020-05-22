


#ifndef FLYQUEUE
#define FLYQUEUE


template<typename T>
class FlyQueue
{
private:
    FlyQueue *prev;
    FlyQueue *next;

    T data;
public:
    FlyQueue();
    ~FlyQueue();

    void Add(T data);
    T Get();
};

template<typename T>
FlyQueue<T>::FlyQueue()
{
    this->prev = this;
    this->next = this;
    this->data = NULL;
}

template<typename T>
FlyQueue<T>::~FlyQueue()
{
    delete this->prev;
    delete this->next;
}

template<typename T>
void FlyQueue<T>::Add(T data)
{
    FlyQueue<T> *q = new FlyQueue<T>();
    q->data = data;
    q->next = this;
    q->prev = this->prev;

    this->prev->next = q;
    this->prev = q;
}

template<typename T>
T FlyQueue<T>::Get()
{
    T data = this->next->data;

    this->next = this->next->next;
    this->next->prev = this;

    return data;
}



#endif

