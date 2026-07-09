# altitude-hold-controller

A simulated altitude hold controller using a PID control loop, written in C.

A ball is rendered on screen and pulled toward a fixed setpoint by a PID
controller. Wind gusts can be applied to push it off course, and the PID
gains and gust strength can be tuned live through an on-screen panel.

## Features

- Real-time physics simulation (SDL3 for windowing/rendering)
- PID control loop driving the ball toward its setpoint
- Live-tunable Kp, Ki, Kd, and gust speed via a Nuklear UI panel
- Keyboard-controlled wind disturbance

## Requirements

- GCC and `make`
- SDL3 (headers and library already included in `include/` and `lib/`)

## Building

```
make
```

This produces a `controller` binary. Use `make clean` to remove build
artifacts.

## Running

```
./controller
```

- Arrow keys: apply wind in that direction
- PID Tuning panel: drag sliders to adjust `kp`, `ki`, `kd`, and gust speed

## Project Structure

```
src/     main application, PID controller, UI panel
sim/     physics engine and ball entity
include/ project headers, plus bundled SDL3 and Nuklear headers
docs/    software requirements (SRS.md)
lib/     prebuilt SDL3 library
```

## Design Docs

See [docs/SRS.md](docs/SRS.md) for the full list of functional and
non-functional requirements.

## License

MIT — see [LICENSE](LICENSE).
