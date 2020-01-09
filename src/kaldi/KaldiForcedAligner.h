#ifndef KALDIFORCEDALIGNER_H
#define KALDIFORCEDALIGNER_H

#include <QObject>
#include <QString>
#include "ForcedAligner.h"

namespace Praaline {
namespace ASR {

struct KaldiForcedAlignerData;

class KaldiForcedAligner : public ForcedAligner
{
    Q_OBJECT
public:
    explicit KaldiForcedAligner(QObject *parent = nullptr);
    ~KaldiForcedAligner();

    bool alignTokens(const QString &waveFilepath, RealTime timeFrom, RealTime timeTo,
                     Praaline::Core::IntervalTier *tierTokens, int &indexFrom, int &indexTo,
                     bool insertLeadingAndTrailingPauses,
                     QList<Praaline::Core::Interval *> &outPhonesList, QString &outAlignerOutput) override;

private:
    KaldiForcedAlignerData *d;

    void mfcc_func(const QString &mfcc_directory, const QString &log_directory,
                   const QString &job_name, const QString &mfcc_config_path);

};

} // namespace ASR
} // namespace Praaline

#endif // KALDIFORCEDALIGNER_H
