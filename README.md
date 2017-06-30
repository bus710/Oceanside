# gombed

This repository explains that how I have developed a prototype telemetry project based on An Opensouce programming language "Golang" (from Google) and a realtime OS "MBED OS 5" (from ARM).  
  
본 프로젝트는 구글에서 비롯된 오픈소스 프로그래밍 언어인 Golang과 ARM에서 제공하는 실시간 OS인 MBED OS 5를 이용하여 프로토타입 원격 제어계측 프로젝트를 개발하는 내용을 담고 있습니다. 

## Maintainer
  
SJ Kim  
- Profile: [bus710.net](http://bus710.net)  
- Contact: <<bus710@gmail.com>>  

## Disclaimer

This project shows developing a certain computer system. Please be aware that the arthor doesn't have responsibility about anything, which cause harmful result in physical, mental, and financial if you follow it. 

## Table of Contents
- [Summary](#summary)
- [Hardware](#hardware)
- [Firmware](#firmware)
- [Server](#server)
- [Clients](#clients)
- [Deploy](#deploy)
- [Reference](#reference)

## Summary

Nowadays, Embedded Engineers are not only requested to develop realtime embedded software but also requested to develop IT system to communicate with remote systems to deliver realtime data to clients. In order to satisfy the needs from our customer (or our team), having rapid prototyping tools might be helpful to show the proof of the concept in your idea note. 

Here I share a simple and comprehensive project about the way I tried to make a combination of Golang and MBED OS 5 so that readers can utilize it to build your own telemetry project. The following sections are linked to sub documents to explain the detail of each steps to build sub modules to make our eventual application, which would work seamlessly.

<img src="image/1.jpg" alt="A prototype of this project" style="width: 100px;"/>

**In writing this guide there is an assumption that the reader is well experienced about Linux. In fact, all the step will be done in both Desktop (Mint 18) and ARM aarch64 server (Ubuntu 16.04.2).**

## Hardware

[How to Make the Hardware](md/01_hardware.md): 
This section explains how to get/make the required hardware. Kicad and Draftsight are used for the custom hardware but don't worry! since the design files (gerber and dxf) for this project are provided in this repository.

## Firmware

[How to develop the Firmware](md/02_firmware.md):
This section explains how to install the realted tools and develop the actual MBED OS 5 based realtime firmware.  

## Server

[How to handle requests from remote and local by Golang Server](md/03_server.md): This section explains how to install the related tools and develop the actual golang based server to deal with in-out bound requests. 

## Clients

This section consists of 3 sub sections for the different clients by using Jupyter notebook for researchers, Unity3D for XR developers, and ROS for robotists.

[Jupyter](md/04_jupyter.md) is well known Opensource project among data scientists. GOMBED system opens WebSocket so that Jupyter's may have interactive widget, which show realtime graph to minotor data in realtime.   

[Unity3D](md/05_unity3d.md) is well known Commercial project and it has very easy way to communicate via WebSocket so that Unity developers, who want to read sensor data to make realistic XR contents, may leverage GOMBED project.

[ROS](md/06_ros.md) is de facto middleware for robotists. Some robot may need enviromental data from infrastructure so that GOMBED can prepare the data and share with ROS based system. 

## Deploy

[Docker](md/07_docker.md) provides lightweitght container mechanism to deploy applications and its environment together. Here we will see how GOMBED can be automatically deployed to remote systems. 

### Reference

1. [aaa]()
2. [aaa]()
3. [aaa]()
