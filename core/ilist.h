#ifndef ILIST_H
#define ILIST_H

#include <vector>

// Noop deleter
template <typename T> struct destructor {
   void operator()(T& ptr) {}
};

// deleter for pointers
template <typename T> struct destructor<T*> {
   void operator()(T* ptr) { delete ptr; }
};

template<class T> class IListNode {
    int id;
    using destructor_T = destructor<T>;

    public:
    T value;
    
    IListNode(const int id) {
        this->id = id;
    }

    ~IListNode() {
        destructor_T(this->value);
    }

    int get_id() { return this->id; }

};

// IList: add and remove objects, keep existing ids, always set/return lowest ID
template<class T> class IList {
    std::vector<IListNode<T>*> nodes;
    std::vector<int> node_positions;

    public:

    IList() = default;

    ~IList() {
        for(int i = 0; i < nodes.size(); i++)
            delete nodes[i];
        nodes.clear();
    }

    const int gen_id(const int position) {
        int node_positions_size = node_positions.size();
        if(!node_positions_size) {
            node_positions.push_back(position);
            return 0;
        }
        for(int i = 0; i < node_positions_size; i++) {
            if(node_positions[i] < 0) {
                node_positions[i] = position;
                return i;
            }
        }
        node_positions.push_back(position);
        return node_positions_size;
    }

    const int add(T e) {
        int new_id = gen_id(nodes.size());
        IListNode<T> node(new_id);
        node.value = e;
        nodes.emplace_back(node);
        return new_id;
    }

    const bool add_with_id(T e, const int id) {
        if(id < 0)
            return false;
        int e_id = -1, node_positions_size = node_positions.size();
        if(id >= node_positions_size) {
            int todo = node_positions_size - id;
            while(--todo) 
                node_positions.push_back(-1);
            node_positions.push_back(id);
            e_id = id;
        }
        if(node_positions[id] == -1) {
            e_id = id;
        }
        if(e_id >= 0) {
            IListNode<T> node = IListNode<T>(e_id);
            node.value = e;
            nodes.emplace_back(node);
            node_positions[e_id] = nodes.size() - 1;
            return true;
        }
        return false;
    }

    void remove(const int id) {
        if(exists(id)) {
            int position = node_positions[id];
            nodes.erase(nodes.begin() + position);
            node_positions[id] = -1;
        }
    }

    bool exists(const int id) {
        return (0 <= id < node_positions.size()) && node_positions[id] == -1;
    }

    T operator[](int id) { return nodes[node_positions[id]]->value; }

    const int count() { return nodes.size(); }
};

#endif