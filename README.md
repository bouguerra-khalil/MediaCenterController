<h1 style="text-align:center"> Media Center Controller </h1>
<img style="display: block; margin: auto;" alt="photo"  width="400" src="./images/remotecontroller.png">
Media Center - Controller project is a tool devllopped in C++ & Java Swing to create a media center on the server side and a  remote controller  though a java  interface on the client side.

## Features: 
- **Add Media files objects to your media center collection**:

supported Formats : 
    - Photos : JPEG,TIFF,GIF,BMP,PNG,SVG
    - Videos : WEBM,MKV,FLV,AVI,MOV,MP4,MPG,M4V
    - Audio  : M4A,MP3,WEBM

- **Possibitly of  adding chapter delimiters for the movies**: The ability to devide the videos of movies  into chapters and store that along the media object.

- **Groupping MediaFiles**: 
    - Same media type groups: eg: Video in Spain, Marriage Album,.. 
    - Generic media groups: Telecom-Paris Media

- **Search MediaFiles / Groups**
- **Play Media on the server** 


## Usage
- On  Server Side : 
```console
$ cd Server 
$ make run
```
- On  Client Side : 

```console
$ cd Client 
$ make run
```




