#include "audio\Singularity.Audio.h"

namespace Singularity
{
	namespace Audio
	{
		#pragma region Constructors and Finalizers

		AdaptiveProperty::AdaptiveProperty(String name, AdaptiveParameter* parent, float importance) : m_pName(name), m_pParent(parent), m_fImportance(importance)
			{
				//AdaptivePropertyPoint point;
				//point.position = Vector2(parent->GetMin(), 1.0f);
				//point.curve = Linear;
				//m_pPoints.push_back(point);

				//point.position = Vector2(parent->GetMax(), 1.0f);
				//point.curve = Linear;
				//m_pPoints.push_back(point);
			}

			AdaptiveProperty::~AdaptiveProperty()
			{

			}

			AdaptiveParameter* AdaptiveProperty::GetParent()
			{
				return m_pParent;
			}

			String AdaptiveProperty::GetName()
			{
				return m_pName;
			}

			float AdaptiveProperty::GetImportance()
			{
				return m_fImportance;
			}

			float AdaptiveProperty::GetValueAtPoint(float xval)
			{

				if (xval > this->m_pParent->GetMax())
				{
					//point = m_parent.Max;
					xval = this->m_pParent->GetMax();
				}

				if (xval < this->m_pParent->GetMin())
				{
					xval = this->m_pParent->GetMin();
				}

				//m_points.OrderBy(Vector2);

				//List<Vector2> keys = m_points.Keys.ToList();
				//SortVectors(keys);

				// these SHOULD be loaded in order. I can't COUNT on it, but we'll make the assumption
				// for now. :/ yay lack of time!

				//this->m_pPoints;
				for (unsigned i = 0; i < this->m_pPoints.size(); i++) // the only reason this works is the first case should catch at size
				{
					if (m_pPoints[i].position.x == xval)
						return (m_pPoints[i].position.y); // if we're on the point, we don't need to calculate it

					// worst case I put a count check in here :/
					if (m_pPoints[i].position.x < xval && m_pPoints[i + 1].position.x > xval)
						return FindValueOnCurve(xval, m_pPoints[i], m_pPoints[i + 1]);
				}

				return -1.0f; // failed
			}


			float AdaptiveProperty::FindValueOnCurve(float currentPoint, AdaptivePropertyPoint startPoint, AdaptivePropertyPoint endPoint)
			{

				float retval = -1.0f;
				if (startPoint.curve == LINEAR)
				{
					// find the total length of the curve and how far along it we are
					//float total = endPoint - startPoint;
					//float current = currentPoint - startPoint;
					// because we're linear, we can just calculate pretty easily what we need
					//float percentage = current / total;
					float percentage = (currentPoint - startPoint.position.x) / (endPoint.position.x - startPoint.position.x); // get the percentage of how far along the curve we are
					retval = startPoint.position.y + (percentage * (endPoint.position.y - startPoint.position.y)); // weight it -- get the change and add it to the startvalue
				}

				if (startPoint.curve == COSINE)
				{
				}

				if (startPoint.curve == EXPONENTIAL)
				{
				}

				if (startPoint.curve == LOGARITHMIC)
				{
				}

				return retval; // if we have -1.0f, we're in trouble

			}

			void AdaptiveProperty::SetName(String name)
			{
				m_pName = name;
			}

			void AdaptiveProperty::SetImportance(float importance)
			{
				this->m_fImportance = importance;
			}

			void AdaptiveProperty::DefinePoint(AdaptivePropertyPoint point)
			{
				this->m_pPoints.push_back(point);
			}

		#pragma endregion
	}
}