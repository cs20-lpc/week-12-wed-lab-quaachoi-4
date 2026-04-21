template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    if(N == M)
    {
        throw runtime_error("Hash table is full");
    }

    for(int i = 0; i < M; i++) 
    {
        //
        int index = probeIndex(key, i);

        if(!occupied[index]) 
        {
            table[index] = key;
            occupied[index] = true;
            N++;
            return index;
        }

        if(occupied[index] && table[index] == key) {
            return index;
        }

        //if this loops, then there is a collision.
    }

    throw runtime_error("No available slot found");
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    for(int i = 0; i < M; i++) 
    {
        int index = probeIndex(key, i);

        if(!occupied[index]) 
        {
            return {false, 0};
        }

        if(table[index] == key) 
        {
            return {true, index};
        }
    }

    return {false, 0};
}
