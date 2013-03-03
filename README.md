Welcome !
=======

__Apricot__ is a web application development library for C++. It tries to create a
simple yet effective way for programmers to create blazing fast websites in a natural way.

Being inspired by Node.js, we've tried to replicate most of the features in it. Like Node, it has a built in HTTP server that can be customized according to the users project environment (the developers can specify the server’s name, maximum number of requests, single threaded or multi-threaded and many more features).

## Compiling the examples on *nix

To compile the examples or the library you need CMake 2.8 or higher.

__Installing CMAKE on Debian \ Ubuntu \ Kubuntu etc.__
`sudo apt-get install cmake`

__Installing CMAKE on Fedora \ RedHat \ Centos__
`sudo yum install cmake`

### I have CMAKE what now?

```bash
git clone https://github.com/FeralLabs/Apricot.git
cd Apricot/examples/BasicHTTP
mkdir build
cd build
cmake ..
make
```

And that's all
