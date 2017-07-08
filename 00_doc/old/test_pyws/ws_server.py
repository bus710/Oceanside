#!/usr/bin/env python

import sys

sys.path.append("/usr/local/lib/python3.5/dist-packages")

import asyncio
import websockets


async def hello(websocket, path):
    name = await websocket.recv()
    print("< {}".format(name))

    greeting = "hello {}!".format(name)
    await websocket.send(greeting)
    print("> {}".format(greeting))

start_server = websockets.serve(hello, 'localhost', 8765)

asyncio.get_event_loop().run_until_complete(start_server)
asyncio.get_event_loop().run_forever()
