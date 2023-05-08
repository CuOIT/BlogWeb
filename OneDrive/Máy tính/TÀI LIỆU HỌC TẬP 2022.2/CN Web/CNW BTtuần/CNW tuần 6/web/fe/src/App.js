import logo from './logo.svg';
import {useState,useEffect} from 'react'
import './App.css';

function App() {
  const [blogList,setBlogList]=useState([
    // {
    //   title:"Con bo",
    //   image:"null",
    //   body:"This is a blog",
    // },
    // {
    //   title:"Con cho",
    //   image:"null",
    //   body:"This is a blog",
    // }
    // ,{
    //   title:"Con trau",
    //   image:"null",
    //   body:"This is a blog",
    // },{
    //   title:"Con ngua",
    //   image:"null",
    //   body:"This is a blog",
    // },{
    //   title:"Con nguoi",
    //   image:"null",
    //   body:"This is a blog",
    // },
    // {
    //   title:"Con nai",
    //   image:"null",
    //   body:"This is a blog",
    // },
    // {
    //   title:"Con de",
    //   image:"null",
    //   body:"This is a blog",
    // }
    // ,{
    //   title:"Con bo",
    //   image:"null",
    //   body:"This is a blog",
    // },{
    //   title:"Con bo",
    //   image:"null",
    //   body:"This is a blog",
    // },{
    //   title:"Con bo",
    //   image:"null",
    //   body:"This is a blog",
    // }
  ])
  const [filteredBlogList,setFilteredBlogList]=useState([]);
  useEffect(()=>{
    console.log("USE");
    fetch("http://localhost:3001/api/blogs").then(res=>{
    return  res.json();
  }).then(res=>{
    console.log("RERENDER");
    console.log(res.data);
    // res.data.forEach(item=>item.body=item.body||"undefined");
    setFilteredBlogList(res.data);    
    setBlogList(res.data);
  }) 
    setFilteredBlogList(blogList);
  
  },[]);
  useEffect(()=>{
    console.log(filteredBlogList);
  },[filteredBlogList]);  

  const handleInput=(event)=>{
    const filter=blogList.filter(item=>item.title.toLowerCase().includes(event.target.value.toLowerCase()));
    setFilteredBlogList(filter);
  }
  return (
    <div className="App">
      <div className="container">
        <div className="header">
          WELCOME TO KNOCK-BLOGS
        </div>
        <div className="searchBox">
          <input className="searchInput" id="sInput" type="text" onChange={handleInput} placeholder='Type blog title here...'/>
          {/* <input className="searchInput"  type="text"  placeholder='Type blog title here...'/> */}
        </div>
        <div className="blogList">
          {filteredBlogList.map((item,index)=>
          <div key={index} className="blog">  
            <div className="titleBlog">{item.title}</div>
            <img className="imgBlog" alt="nope" src={item.image}/>
            <div className="bodyBlog">{item.body}</div> 
          </div>)}
        </div>
      </div>
    </div>
  );
}

export default App;
