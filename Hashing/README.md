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


# Chaining 
- here we are using linked list which store all the element comes at the place of the index 
- there is no size limit here

- here we do time analysis base on the loading factor (lambda) = totalelement/size   (here we assume that each hashtable index contain equal no of element to analysis)


# Linear Probing 
- (BOUNDED OF SIZE)
- In Linear probing if collision occurs element placed at next empty space .
- h'[x] = (h[x]%10 + f[i]) % 10 where f[i] = i , i= 0,1,2,3... this liner hash function represent the same statement of linear probing 
    - here f[i] is the probing function 

- loading factor [lambda] = number of key / size of hash table
    - in linear probing [lambda] <= 0.5.
    - that mean half of the hash table should be empty that help to fast search

- average succesful time = 1/[lambda] ln[ 1 / (1-[lambda]) ]
- average unsuccesful time = 1 / (1-[lambda])

- whille {DELETE OPERATION} is performed we need to rearrage all element after it that time taking and increse complexcity 
    - to reduce complexcity we use Rehashing (get out all element and again insert)
    - therefore it not suggested not perform delete operation in linear probing
    - But if want use flag 0,1 that repersent the key is present or not.
    
- linear probling also lead problem of primary clusterig element form groups and create clusters


# Quadratic probing 
- the only difference is in the probing function here it is the p[i] = i*i
    - so it help in prevent clustering of the elements

- average successful search time   -ln(1-[lambda]) / [lambda]
- average unsucessful search time  1/(1-[lambda])


# Double Hashing
- here we use two hash function in which other is behave as the prob for the hash function 
- first hash function  h1[x] = x%10
- second hash function h2[x] = R - (x% R) 
    - second hash should not result 0 
    - and cover all the index in the table
- modified hash h'[x] = (h1[x] + i*(h2[x])) % 10 where i=0,1,2,3...


# Various Hash function 
- ### Mod
    - h[x] = (x % size) + 1 (if want not include 0)
- ### Mid Square
    - find square of the key. let [11]*[11] = 121
    - find second digit of it . for 11 it is 2 
    - so, idx = 2
- ### Folding
    - here you reduce the size of the number if large 
    - eg. 123456 here i divide into pair group and add them
    - 12 + 34 + 56 = 102 so idx = 102
    - futher you perform other operation like mod and again folding etc.