#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonFX.h>
#include <frc/Solenoid.h>
#include <units/voltage.h>

#include "Constants.h"

using ctre::phoenix::motorcontrol::can::WPI_TalonFX;

namespace cb {
    class Arm : public frc2::SubsystemBase {
    private:
        frc::Solenoid m_solenoid { SOLENOID_ID, frc::PneumaticsModuleType::CTREPCM, 0 };

        WPI_TalonFX m_limb { LIMB_ID };
    public:
        //true for one and false for off
        void activateSolenoid(bool onOff);

        void moveLimb(units::volt_t voltage);
    };

    inline Arm g_arm;
}