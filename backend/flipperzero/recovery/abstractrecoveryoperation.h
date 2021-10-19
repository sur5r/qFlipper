#pragma once

#include "abstractoperation.h"

namespace Flipper {
namespace Zero {

class Recovery;
class DeviceState;

class AbstractRecoveryOperation : public AbstractOperation
{
    Q_OBJECT

public:
    AbstractRecoveryOperation(Recovery *recovery, QObject *parent = nullptr);
    virtual ~AbstractRecoveryOperation() {}

    void start() override;
    void finish() override;

protected:
    Recovery *recovery() const;
    DeviceState *deviceState() const;

private slots:
    void onDeviceOnlineChanged();
    virtual void advanceOperationState() = 0;

private:
    Recovery *m_recovery;
};

}
}

