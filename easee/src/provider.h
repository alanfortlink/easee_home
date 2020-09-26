#ifndef EASEE_PROVIDER_H
#define EASEE_PROVIDER_H

namespace easee {

template <class T>
class Provider {
   public:
    static Provider* instance() {
        if (!d_instance) {
            d_instance = new Provider<T>();
        }
        return d_instance;
    }

    inline const T& get() { return d_data; }
    void set(const T& data) { d_data = data; }

   private:
    Provider<T>() : d_data() {}
    ~Provider<T>() {}
    T d_data;

    static Provider<T>* d_instance;
};

template <class T>
Provider<T>* Provider<T>::d_instance = nullptr;

};  // namespace easee

#endif
