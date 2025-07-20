# Learning what is actually is Hashing
- why hashing
- ideal hashing 
- modulus hash function
- drawbacks
- solutions

## hashing is trying to search in less than O(log(n)) times almost constant time

- For Binary O(log(n)) and Linear search O(n)
- In hashing element are palce to same as the index number like for 3-index 3, 67-index 67 respectively that make fastest search in O(1) time 
- But what if number of element is large like we have one element value is 445654 than we need that size of array .
- so hashing leads to wastage of the space 

## Now how rectify these drawbacks of hashing
- types of mapping 
    - one to one (function)
    - one to many 
    - many to one  (function)
    - many to many 

- we have [3,4,5,7] and in hash-table [_,_,_,3,4,5,_,7] and hash function for it is h(x) = x (IDEAL HASHING)
- space required is very huge for ideal hashing


- MODIFING hash function let h(x)=x%10 now hash-table for the [2,5,15,4] is [ , ,2, ,4,[5,15]] 
- required space is reduce as i take hashtable of size 6 but the max element is 15  
- but observe here that multiple value for a index in hash table is collision and we say the h(x) is many to one function

## how to rectify the collision
- ### open hashing 
    - here we consume extra space
        - chaining (one of the method)
- ### close hashing
    - here we are not consume extra space 
        - Linear probing
        - Quadratic probing
        - Double probing


## Chaining 
- here we are using linked list which store all the element comes at the place of the index 
- there is no size limit here

- here we do time analysis base on the loading factor (lambda) = totalelement/size   (here we assume that each hashtable index contain equal no of element to analysis)



