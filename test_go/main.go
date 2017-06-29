package main

import (
	"fmt"
	"log"
	"time"

	"github.com/tarm/serial"
)

func serialReader(main_rxchan chan<- string, main_txchan <-chan string) {
	c := &serial.Config{Name: "/dev/ttyS1", Baud: 115200, ReadTimeout: time.Second * 2}
	s, err := serial.OpenPort(c)
	if err != nil {
		log.Fatal(err)
	}

	for {
		/*
			buf := make([]byte, 128)
			n, err := s.Read(buf)
			if err != nil {
				log.Fatal(err)
				break
			}

			if n > 0 {
				fmt.Println(time.Now(), ":\t", string(buf[:n]))
			}
			time.Sleep(1)
		*/
		select {
		case <-main_txchan:
			fmt.Println(main_txchan)
		default:
			buf := make([]byte, 128)
			n, err := s.Read(buf)
			if err != nil {
				log.Fatal(err)
				break
			}

			if n > 0 {
				main_rxchan <- string(buf)
				//fmt.Println(time.Now(), ":\t", string(buf[:n]))
			}
			time.Sleep(100 * time.Millisecond)
		}
	}
}

func main() {

	fmt.Println("start.")

	main_rxchan := make(chan string)
	main_txchan := make(chan string)

	go serialReader(main_rxchan, main_txchan)

	for {
		select {
		case <-main_rxchan:
			fmt.Println(time.Now(), ":\t", <-main_rxchan)
		default:
			//fmt.Println(time.Now(), "waiting")
			time.Sleep(100 * time.Millisecond)
		}
		time.Sleep(1)
	}
}
