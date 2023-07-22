const arr =["피카츄","라이츄","파이리","꼬부기","피카츄","파이리"]

```arr.reduce((acc,cur,index,array)=>{
    return acc;
},"초기값")```


// const obj = { 피카츄:2 라이츄:1}
// obj.피카츄


const result = arr.reduce((acc,cur,index,array)=>{
    if(acc[cur]){
        acc[cur] = acc[cur]+1;
        }
        else{
            acc[cur]=1;
        }
    return acc;
},{})