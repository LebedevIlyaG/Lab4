#pragma once

template <class T>
class TNode
{
public:
  TNode<T>* next;
  TNode<T>* prev;
  T data;

  TNode();
  TNode(TNode<T>* n, TNode<T>* p, T d);
};
template <class T>
TNode<T>::TNode()
{
  next = nullptr;
  prev = nullptr;
}

template <class T>
TNode<T>::TNode(TNode<T>* n, TNode<T>* p, T d)
{
  next = n;
  prev = p;
  data = d;
}

template <class T>
class TListIterator;

template <class T>
class TList
{
protected:
  TNode<T>* begin_;
  TNode<T>* end_;
  int count;

public:
  TList();
  TList(const TList<T>& p);
  ~TList();

  void PushBegin(T d);
  void PushEnd(T d);

  void DelBegin();
  void DelEnd();

  TListIterator<T> begin();
  TListIterator<T> end();


};

template <class T>
class TListIterator
{
protected:
  TList<T>& list;
  TNode<T>* node;
public:
  TListIterator(TList<T>& list_, TNode<T>* node_);
  TListIterator<T>& operator++();
  T operator*();
  bool operator != (const TListIterator<T>& p);
};

template<class T>
inline TListIterator<T>::TListIterator(TList<T>& list_, 
  TNode<T>* node_): list(list_), node(node_)
{

}

template<class T>
inline TListIterator<T>& TListIterator<T>::operator++()
{
  node = node->next;
  return *this;
}

template<class T>
inline T TListIterator<T>::operator*()
{
  return node->data;
}

template<class T>
inline bool TListIterator<T>::operator!=(const TListIterator<T>& p)
{
  if (node == p.node)
    return false;
  return true;
}

template<class T>
inline TList<T>::TList()
{
  begin_ = nullptr;
  end_ = nullptr;
  count = 0;
}

template<class T>
inline TList<T>::TList(const TList<T>& p)
{
  TNode<T>* tmp = p.begin_;
  begin_ = new TNode<T>(nullptr, nullptr, p.begin_->data);
  TNode<T>* tmp2 = begin_;

  while (tmp->next != nullptr)
  {
    TNode<T>* a = new TNode<T>(nullptr, tmp2, tmp->next->data);
    tmp2->next = a;
    tmp = tmp->next;
    tmp2 = tmp2->next;    
  }
  end_ = tmp2;
  count = p.count;
}

template<class T>
inline TList<T>::~TList()
{
  TNode<T>* tmp2 = begin_;
  while (tmp2 != nullptr)
  {
    tmp2 = tmp2->next;
    delete begin_;    
    begin_ = tmp2;
  }
  begin_ = nullptr;
  end_ = nullptr;
  count = 0;

}

template<class T>
inline void TList<T>::PushBegin(T d)
{
  TNode<T>*  tmp = new TNode<T>(begin_, nullptr, d);
  if (begin_ != nullptr)
    begin_->prev = tmp;
  else
    end_ = tmp;
  begin_ = tmp;
  count++;
}

template<class T>
inline void TList<T>::PushEnd(T d)
{
  TNode<T>* tmp = new TNode<T>(nullptr, end_, d);
  if (end_ != nullptr)
    end_->next = tmp;
  else
    begin_ = tmp;
  end_ = tmp;
  count++;
}

template<class T>
inline void TList<T>::DelBegin()
{
  if (begin_ == nullptr)
    throw "no";

  TNode<T>* tmp = begin_;
  begin_ = begin_->next;
  if (begin_ != nullptr)
    begin_->prev = nullptr;

  delete tmp;
  count--;
}

template<class T>
inline void TList<T>::DelEnd()
{
  if (begin_ == nullptr)
    throw "no";

  TNode<T>* tmp = end_;
  end_ = end_->prev;
  if (end_ != nullptr)
    end_->next = nullptr;

  count--;
  delete tmp;
}

template<class T>
inline TListIterator<T> TList<T>::begin()
{
  return TListIterator<T>(*this, begin_);
}

template<class T>
inline TListIterator<T> TList<T>::end()
{
  return TListIterator<T>(*this, nullptr);
}
