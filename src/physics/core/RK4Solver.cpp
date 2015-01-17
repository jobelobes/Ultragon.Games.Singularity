#include "physics\Singularity.Physics.h"

namespace Singularity
{
	namespace Physics
	{
		namespace Core
		{
			IMPLEMENT_OBJECT_TYPE(Singularity.Physics.Core, RK4Solver, Singularity::Physics::Core::ISolver);

			#pragma region Constructors and Finalizers
			RK4Solver::RK4Solver()
			{


			}
			#pragma endregion

			#pragma region Methods
			PhysicsDerivative RK4Solver::Evaluate(float elapsedTime, PhysicsObject& object, PhysicsState& state, const PhysicsDerivative &d)
			{
				state.Position += d.Velocity * elapsedTime;
				state.Momentum += d.Force * elapsedTime;
				state.Orientation += d.Spin * elapsedTime;
				state.AngularMomentum += d.Torque * elapsedTime;
				state.Velocity = state.Momentum * object.InverseMass;
				state.AngularVelocity = state.AngularMomentum * object.InverseTensor;
				D3DXQuaternionNormalize(&state.Orientation, &state.Orientation);
				state.Spin = 0.5 * Quaternion((state.AngularVelocity.x < 0.0001f ? 0 : state.AngularVelocity.x), (state.AngularVelocity.y < 0.0001f ? 0 : state.AngularVelocity.y), (state.AngularVelocity.z < 0.0001f ? 0 : state.AngularVelocity.z), 0) * state.Orientation;
				
				PhysicsDerivative output;
				output.Velocity = state.Velocity;
				output.Spin = state.Spin;
				output.Force = state.Force - state.Velocity * object.LinearDrag;
				output.Torque = state.Torque - state.AngularMomentum * object.AngularDrag;
				return output;
			}

			void RK4Solver::Update(float elapsedTime, PhysicsObject& object, PhysicsState& state)
			{
				PhysicsDerivative a;
				a.Velocity = state.Velocity;
				a.Spin = state.Spin;
				a.Force = state.Force - state.Velocity * object.LinearDrag;
				a.Torque = state.Torque - state.AngularMomentum * object.AngularDrag;

				PhysicsDerivative b = this->Evaluate(elapsedTime * 0.5f, object, state, a);
				PhysicsDerivative c = this->Evaluate(elapsedTime * 0.5f, object, state, b);
				PhysicsDerivative d = this->Evaluate(elapsedTime, object, state, c);
				
				state.Position += 0.16667f * elapsedTime * (a.Velocity + 2.0f * (b.Velocity + c.Velocity) + d.Velocity);
				state.Momentum += 0.16667f * elapsedTime * (a.Force + 2.0f * (b.Force + c.Force) + d.Force);
				state.Orientation += 0.16667f * elapsedTime * (a.Spin + 2.0f * (b.Spin + c.Spin) + d.Spin);
				state.AngularMomentum += 0.16667f * elapsedTime * (a.Torque + 2.0f * (b.Torque + c.Torque) + d.Torque);

				state.Velocity = state.Momentum * object.InverseMass;
				state.AngularVelocity = state.AngularMomentum * object.InverseTensor;
				D3DXQuaternionNormalize(&state.Orientation, &state.Orientation);
				state.Spin = 0.5 * Quaternion(state.AngularVelocity.x, state.AngularVelocity.y, state.AngularVelocity.z, 0) * state.Orientation;
				state.TotalTime += elapsedTime;
				state.Force = Vector3(0,0,0);
				state.Torque = Vector3(0,0,0);
			}
			#pragma endregion
		}
	}
}


