const arr = [1,2,3,4,5]

```arr.reduce((acc,cur,index,array) => {
    return acc + cur
},"초기값")```

arr.reduce((acc,cur) => {
    return acc + cur
}, [])
