# Ra-08H-KIT LoraWAN module : US915 TTN/Helium experiments

This is a fork of the official [ASR6601 repository](https://github.com/asrlora/asr_lora_6601) integrating the [Ra-08H develoment guide](https://github.com/Ai-Thinker-Open/Ai-Thinker-LoRaWAN-Ra-08/).

## Setup

See [Ra-08 instruction](https://github.com/Ai-Thinker-Open/Ai-Thinker-LoRaWAN-Ra-08/#5sdk-preparation)

> Python script for burning don't work on all linux system.
>
> Use Windows version [tools/programmer](./tree/master/tools/programmer)

## Examples for Ra-08H module

See directory [/projects/RA08HKIT-EVAL/examples](./tree/master/projects/RA08HKIT-EVAL/examples)

- led : Flashing 3 onboard leds.
- lorawan/class_c : Connecting device on TTN/Helium network using US915 subband #2.

## Resources & docs

+ ASR6601 : (https://asriot.readthedocs.io/en/latest/ASR6601/)
+ Ra-08H : (https://docs.ai-thinker.com/en/lorawan#ra-08_h_resource_summary)
+ LoRaMac-node : (https://github.com/Lora-net/LoRaMac-node/tree/v4.4.0) ASR6601 seems to be based on version ~ 4.4.

- TTN US915 band : (https://www.thethingsnetwork.org/docs/lorawan/frequency-plans/#us902-928)
- Helium US915 band : (https://docs.helium.com/iot/lorawan-frequency-plans/#us915)