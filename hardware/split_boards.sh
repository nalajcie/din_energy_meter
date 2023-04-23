#!/bin/bash

set -e -x

kikit separate --source 'annotation; ref: B1' din_energy_meter.kicad_pcb power_board.kicad_pcb
kikit separate --source 'annotation; ref: B2' din_energy_meter.kicad_pcb metering_board.kicad_pcb
