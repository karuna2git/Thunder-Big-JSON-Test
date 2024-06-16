# Thunder-Big-JSON-Test
[![License](https://img.shields.io/badge/License-Apache_2.0-blue.svg)](https://opensource.org/licenses/Apache-2.0) 

This is a simple test plugin to understand and report the JSON Parsing issue that is present in WPEFramework (aka Thunder).

This TestPlugin simply publishes event every 3s. It sends a big JSON message on every 4th iteration.

The TestConsumer is something that subscribed to the above event and expected to receive all the events in order.

## Issue Reported
The TestConsumer is receiving only the 1st 3 events.

The 4th will not be notified to the Consumer. Stuck at Thunder Layer itself.

The 5th will be received by Thunder layer and it will mess it up with the 4th message that is yet to be notified; and Deserialize errors will be reported combining both 4th & 5th messages.

After that No event will be received/notified. Thunder layer will be in bad state.
