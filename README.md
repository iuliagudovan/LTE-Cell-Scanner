# An enhanced LTE Cell Scanner/tracker
- Support both FDD and TDD
- OpenCL accelerated
- Full Receiver algorithm for LTE 100 RB downlink (Matlab and GNU Octave scripts)
  - from IQ sample to PDSCH output and RRC SIB messages
- Support HackRF, rtlsdr, BladeRF and USRP

(It has gone too far away from the Evrytania/LTE-Cell-Scanner during the period I had less experience. I won't push this ugly work back. :))

## Build
```
mkdir build
cd build
cmake ../
make
```
By default above builds for rtlsdr. Following arguments could be added at the end of cmake command for different hardwares and options. 
```
-DUSE_BLADERF=1   -- build for BladeRF
-DUSE_HACKRF=1    -- build for HackRF
-DUSE_OPENCL=0    -- disable OpenCL (See notes in later chapter)
```
## Usage
- CellSearch
```
./src/CellSearch --freq-start 1890000000
```
Above tries to search LTE Cell at 1890MHz. Don't know which LTE downlink frequency is in use in your region? Check by the engineering mode of your cell phone or this [website](https://www.spectrummonitoring.com/frequencies.php).

Example output:
```
...
Detected a TDD cell! At freqeuncy 1890MHz, try 0
cell ID: 253
PSS ID: 1
RX power level: -17.0064 dB
residual frequency offset: -48.0366 Hz
            k_factor: 1
...
Detected the following cells:
Meaning -- DPX:TDD/FDD; A: #antenna ports C: CP type ; P: PHICH duration ; PR: PHICH resource type
DPX  CID  A     fc  freq-offset RXPWR  C   nRB  P   PR  CrystalCorrectionFactor
TDD  253  2  1890M         -48h   -17  N  100   N  1/2   0.99999997458380551763
```
- LTE-Tracker
```
./src/LTE-Tracker -f 1890000000
```
- LTE_DL_receiver/Matlab
```
LTE_DL_receiver('../regression_test_signal_file/f1815.3_s19.2_bw20_0.08s_hackrf-1.bin');
```
See [regression_test_signal_file](regression_test_signal_file) for how to capture IQ sapmle to a .bin file via HackRF/rtlsdr/BladeRF/USRP. Lots of captured IQ files are in [LTE-Cell-Scanner-big-file](https://github.com/JiaoXianjun/LTE-Cell-Scanner-big-file).

Example output:
```
...
TDD SFN-864 ULDL-2-|D|S|U|D|D|D|S|U|D|D| CID-216 nPort-2 CP-normal PHICH-DUR-normal-RES-1
SF0 PHICH1 PDCCH1 RNTI: 
...
SF4 PHICH1 PDCCH1 RNTI: SI-RNTI SI-RNTI 
PDCCH   No.0  4CCE: Localized VRB from RB0 to RB11 MCS-7 HARQ-0 NEWind-0 RV-0 TPC-1 DAI-0
Calling asn1c decoder (../asn1_test/LTE-BCCH-DL-SCH-decode/progname) for BCCH-DL-SCH-Message.
../asn1_test/LTE-BCCH-DL-SCH-decode/progname tmp_sib_info.per -p BCCH-DL-SCH-Message
<BCCH-DL-SCH-Message>
    <message>
        <c1>
            <systemInformation>
                <criticalExtensions>
                    <systemInformation-r8>
                        <sib-TypeAndInfo>
                                <sib2>
                                    <radioResourceConfigCommon>
                                        <rach-ConfigCommon>
                                            <preambleInfo>
                                                <numberOfRA-Preambles><n52/></numberOfRA-Preambles>
...
```
## Advanced topics
For CellSearch/LTE-Tracker, "-h" can always be used to display available arguments.
### Gain setting
Use "-g X" to set gain value X to hardware. If "-g" is not used, default gain will be used.
Gain is important to get good rx performance. If CellSearch reports like "input level: avg abs(real) 0.00594959 avg abs(imag) 0.00614887", where the numbers are far below 1, larger gain value should be considered.
### carrier-sampling-clock twisted mode
"-t" forces into original carrier-sampling-clock twisted mode, which assumes carrier frequency offset and sampling frequency offset are from the common LO. This assumption speedups the search algorithm. But it is not valid when you add an independent external mixer/converter to your SDR board.

Without "-t" leads to non-twisted mode (default mode).

**0x05. Capture to and reload from raw bin file**

    "CellSearch --freq-start 1860e6 --recbin a.bin" saves signal in a.bin while doing cell search at frequency 1.86GHz
    "CellSearch --loadbin test/f1890_s1.92_g0_0.16s.bin" searches LTE cell in test/f1890_s1.92_g0_0.16s.bin

**0x06. "--num-try x" performs x tries of searching at each frequency.**

When signal is weak, only one try may not have you good luck.

----------------------------------------------------------------------
Notes
----------------------------------------------------------------------

**0x01. About carrier-sampling-clock twisted and non-twisted mode.**

Default mode supports external LNB and fast pre-search.
See detailed explanation in https://github.com/JiaoXianjun/rtl-sdr-LTE , and videos: (inside China): http://v.youku.com/v_show/id_XNjc1MjIzMDEy.html ,
 (outside China): http://www.youtube.com/watch?v=4zRLgxzn4Pc )

**0x02. About OpenCL.**

**0x02.1** Make sure OpenCL SDK (Intel, AMD, Nvidia) has been installed in your system correctly, if you want LTE Scanner accelerated by OpenCL.

**0x02.2 IMPORTANT!** Before run, those kernel files (src/*.cl) should be put IN THE SAME DIRECTORY AS executable program or in $PATH.
Because they need to be compiled and executed by OpenCL runtime after program launch.

**0x02.3 Test an OpenCL example:**

    CellSearch --loadbin test/f1890_s1.92_g0_0.16s.bin --opencl-platform=0 --opencl-device=0 --filter-workitem=32 --xcorr-workitem=2

OpenCL platform and device are specified by "--opencl-platform=idx1 --opencl-device=idx2" to decide which CPU/GPU is used.
When program runs, it tells you how many platforms are detected in total. Default index is 0.

Number of workitems for 6RB channel filter kernel can be specified by "--filter-workitem". Default value is 32.

Number of workitems in the 1st NDrange dimension for PSS frequency-time correlation kernel can be specified by "--xcorr-workitem".
(ATTENTION!!! Now it is omitted because #define FILTER_MCHN_SIMPLE_KERNEL in searcher.h. Turn the pre-define off to use "--xcorr-workitem")
Default value is 2. Number of workitems of PSS correlation'2nd-NDrange-dimension depends on PPM range (use "-p" to change it).

Optimal number of workitems is platform-device dependent. Optimal values should be found according to your computer configuration.

**0x02.4 ATTENTION!!!** If you got -4(CL_MEM_OBJECT_ALLOCATION_FAILURE) or -5(CL_OUT_OF_RESOURCES) error in some OpenCL platform-device, try smaller PPM value to narrow frequency offset range. Because less range less OpenCL work-items needed.

--------------------
News:
--------------------

2014-10: support bladeRF now.

2014-07: Now Matlab can parse SIB automatically by calling asn1c. See doc in asn1_test and http://sdr-x.github.io/LTE-SIB-decoding-by-asn1c/ . (Don't forget compling the progname in your own computer!)

2014-06: SIB message (output by LTE_DL_receiver.m) is decoded successfully! See Matlab/*SIB.txt.

2014-05: 20MHz LTE PDCCH DCI format1A for SI-RNTI has been detected successfully from HACKRF captured signal, and corresponding SIB PDSCH constellation is shown. Run: Matlab/LTE_DL_receiver.m
 (http://youtu.be/2JH_EGdHyYE  http://v.youku.com/v_show/id_XNzE3NDYwMDgw.html)

-----------------------------
Bakcups
------------------------------

Before explore this LTE Scanner, it's better for you to do some homeworks: (my blog: http://sdr-x.github.io/ if you have time)

1. Original FDD only LTE Cell Scanner / Tracker: https://github.com/Evrytania/LTE-Cell-Scanner , by James Peroulas.

2. rtl-sdr ultra cheap USB TV dongle: http://sdr.osmocom.org/trac/wiki/rtl-sdr

3. hackrf board: http://greatscottgadgets.com/hackrf/ , https://github.com/mossmann/hackrf

4. bladeRF board: http://www.nuand.com/  ,  https://github.com/Nuand/bladeRF

COMPATIBLE rtl-sdr and hackrf version (maybe not valid now. If you have issues, try these rev.):

librtlsdr (https://github.com/steve-m/librtlsdr) release v0.5.2 (Not v0.5.3 at least for my computer)

libhackrf (https://github.com/mossmann/hackrf  ) revision around 2014 April 1st.

See TODO if you want to contribute. Any questions or interests, feel free to contact me. putaoshu@gmail.com

Introduction video: (inside China) http://v.youku.com/v_show/id_XNjk3Mjc1MTUy.html ,
(outside China) http://www.youtube.com/watch?v=3hnlrYtjI-4

Introduction video before: (inside China) http://pan.baidu.com/s/1o6qbLGY ,
(outside China) http://www.youtube.com/watch?v=SxZzEVEKuRs

Introduction video before: (inside China) http://v.youku.com/v_show/id_XNjc1MjIzMDEy.html ,
(outside China) http://www.youtube.com/watch?v=4zRLgxzn4Pc

--------------------------------------------------------------------------
Original Readme of James Peroulas's LTE Cell Scanner / Tracker
--------------------------------------------------------------------------
LTE Cell Scanner / Tracker
--------------------------

This is a collection of tools to locate and track LTE basestation cells using
very low performance RF front ends. For example, these tools work with RTL2832
based dongles (E4000, R820T, etc.) which have a noise figure of 20dB, only 8
bits in the A/D, and a crystal with a frequency error of about 100 ppm.

The 'CellSearch' program can be used to search for LTE carriers within a range
of frequencies.  Once an LTE frequency has been located, 'LTE-Tracker' can be
used to monitor and track, in realtime, any LTE cells on that frequency.

The main documentation in html format can be found on the web at:
  http://www.evrytania.com/lte-tools
And in the doc/index.html subdirectory of this distribution.

For questions, comments, or bug reports, contact James Peroulas
james@evrytania.com, or check the bugtracker on github:
  https://github.com/Evrytania/LTE-Cell-Scanner/issues

------
Quick build instructions:
------
  cd LTE-Cell-Scanner
  mkdir build
  cd build
  cmake ..
  make

------
Install:
------
  sudo make install

------
Quick usage instructions:
------

Search for LTE carriers within a common LTE frequency range used in the US:
  CellSearch --freq-start 715e6 --freq-end 768e6

Start tracking LTE cells on frequency 739 MHz:
  LTE-Tracker -f 739000000

