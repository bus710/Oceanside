
[Back to main](../README.md#clients)


### Remove Unity cache data which resets license status
```
rm -r ~/.local/share/unity3d/
```
 
### Uninstall current version
```
sudo dpkg -r unity-editor
```
  
### Download 5.6.1xf1Linux
```
wget http://beta.unity3d.com/download/6a86e542cf5c/unity-editor_amd64-5.6.1xf1Linux.deb
```
   
### Install it
```
sudo dpkg -i unity-editor_amd64-5.6.1xf1Linux.deb
```
    
### Activate unity
```
/opt/Unity/Editor/Unity
```
     
### Update Unity
```
sudo dpkg -i unity-editor_amd64-2017.1.0xb8Linux.deb
```

use 5.6.1 for now. the version 2017.1 has a log in issue. 